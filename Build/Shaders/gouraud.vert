#version 430 core

layout (location = 0) in vec3 vs_position;
layout (location = 1) in vec3 vs_normal;
//layout (location = 1) in vec2 vs_uv;

out vec3 fs_color;
//out vec2 fs_uv;

struct Material
{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

uniform Material material;

struct Light
{
    vec4 position;  
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Light light;

uniform mat4 mvp;
uniform mat4 model_view;

void main()
{
    //fs_color = vs_color;
    //fs_uv = vs_uv;

    //ambient
    vec3 ambient = material.ambient * light.ambient;

    //diffuse
    vec3 normal = normalize(mat3(model_view) * vs_normal);
    vec4 position = model_view * vec4(vs_position, 1);
    vec3 direction_to_light = normalize(vec3(light.position - position));

    // light dot normal
    float lDotN = max(dot(direction_to_light, normal), 0);
    vec3 diffuse = material.diffuse * light.diffuse * lDotN;


    // specular
    vec3 specular = vec3(0); // x, y, y | < 0, 0, 0 >
    if(lDotN > 0.0)
    {
        vec3 direction_to_view = normalize(-position.xyz); // swizzling
        vec3 reflection = reflect(-direction_to_light, normal);
        float intensity = max(dot(direction_to_view, reflection), 0);
        intensity = pow(intensity, material.shininess);
        specular = material.specular * light.specular * intensity;
    }

    

    fs_color = ambient + diffuse + specular;
    gl_Position = mvp * vec4(vs_position, 1.0);
}
