#version 330

// Input vertex attributes
attribute vec3 vertexPosition;
attribute vec2 vertexTexCoord;
attribute vec3 vertexNormal;
attribute vec4 vertexColor;

// Input uniform values
uniform mat4 mvp;
uniform float uTime;

// Output vertex attributes (to fragment shader)
varying vec2 fragTexCoord;
varying vec4 fragColor;

// NOTE: Add here your custom variables

void main()
{
    // Send vertex attributes to fragment shader
    fragTexCoord = vertexTexCoord;
    fragColor = vertexColor;

    // Calculate final vertex position
    gl_Position = mvp * vec4(
            vertexPosition.x, 
            pow(vertexPosition.z/3.0, 2.0) * -0.075 + vertexPosition.y, 
            vertexPosition.z, 
            1.0);
}
