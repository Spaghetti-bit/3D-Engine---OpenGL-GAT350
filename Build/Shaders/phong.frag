#version 430 core

//in vec2 fs_uv;

in vec3 fs_position;
in vec3 fs_normal;

out vec4 out_color;

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

void main()
{
    //ambient
    vec3 ambient = material.ambient * light.ambient;

    //diffuse
    vec3 direction_to_light = normalize(vec3(light.position) - fs_position);

    // light dot normal
    float lDotN = max(dot(direction_to_light, fs_normal), 0);
    vec3 diffuse = material.diffuse * light.diffuse * lDotN;


    // specular
    vec3 specular = vec3(0); // x, y, y | < 0, 0, 0 >
    if(lDotN > 0.0)
    {
        vec3 direction_to_view = normalize(-fs_position); // swizzling
        vec3 reflection = reflect(-direction_to_light, fs_normal);
        float intensity = max(dot(direction_to_view, reflection), 0);
        intensity = pow(intensity, material.shininess);
        specular = material.specular * light.specular * intensity;
    }

    

    out_color = vec4(ambient + diffuse + specular, 1);
	//out_color = texture(baseTexture, fs_uv);
}
