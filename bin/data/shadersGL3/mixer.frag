#version 120

uniform sampler2D red;
uniform sampler2D green;
uniform sampler2D blue;
uniform float colorOn;

uniform vec2 resolution;

#define USE_PHOTOSHOP_ALGORITHM
//#define USE_GENERIC_ALGORITHM

// Generic algorithm to desaturate images used in most game engines
vec4 generic_desaturate(vec3 color, float factor)
{
	vec3 lum = vec3(0.299, 0.587, 0.114);
	vec3 gray = vec3(dot(lum, color));
	return vec4(mix(color, gray, factor), 1.0);
}

// Algorithm employed by photoshop to desaturate the input
vec4 photoshop_desaturate(vec3 color)
{
    float bw = (min(color.r, min(color.g, color.b)) + max(color.r, max(color.g, color.b))) * 0.5;
    return vec4(bw, bw, bw, 1.0);
}

vec4 color = vec4(1.0, 0.0, 0.0, 1.0);

void main() {
    // vec2 uv = gl_FragCoord.xy / resolution.xy;
    if (colorOn > 0.5) {
        gl_FragColor = color; 
    }
    if (colorOn < 0.5) {
#	ifdef USE_GENERIC_ALGORITHM
	    gl_FragColor = generic_desaturate(color.rgb, 1.0);
#	endif
    
#	ifdef USE_PHOTOSHOP_ALGORITHM
        gl_FragColor = photoshop_desaturate(color.rgb);
#	endif
    }
}