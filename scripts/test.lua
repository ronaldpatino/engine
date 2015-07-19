--local foo = Entity.new("/home/ronald/ClionProjects/luallegro/000.bmp",500,100)
--local x = foo.x

--print(x)

--val=cmultiply(2,2)
--print(val)

ENTIDAD_COUNT = 3;
Entidades = {};

function init()

    --for entidadIndex = 1, ENTIDAD_COUNT do
        local Entidad = {};
        Entidad.x = 10;
        Entidad.y = 100;
        Entidad.name = "shoggot";
        Entidad.img = "/home/ronald/ClionProjects/engine/assets/img/shoggoth/000.bmp";
        Entidad.script = "test.lua";
        Entidades[1] = Entidad;

        local Entidad = {};
        Entidad.x = 100;
        Entidad.y = 10;
        Entidad.name = "wolf";
        Entidad.img = "/home/ronald/ClionProjects/engine/assets/img/wolf/000.bmp";
        Entidad.script = "test.lua";
        Entidades[2] = Entidad;


        local Entidad = {};
        Entidad.x = 500;
        Entidad.y = 500;
        Entidad.name = "rat";
        Entidad.img = "/home/ronald/ClionProjects/engine/assets/img/rat/000.bmp";
        Entidad.script = "test.lua";
        Entidades[3] = Entidad;
    --end
end