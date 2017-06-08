#version 150

out vec4 outputColor;

void main()
{
    
    float windowWidth = 1024.0;
    float windowHeight = 768.0;
    
    float r = gl_FragCoord.x / windowHeight;
    float g = 1.0;
    float b = 1.0;
    float a = 1.0;
    outputColor = vec4(r, g, b, a);
}