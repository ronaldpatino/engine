Entities = {};

function init()
    local Entity = {};
    Entity.nombre = "shoggoth";
    Entity.script = "/home/ronald/ClionProjects/engine/scripts/shoggoth.lua"
    Entities[0] = Entity;

    local Entity = {};
    Entity.nombre = "rat";
    Entity.script = "/home/ronald/ClionProjects/engine/scripts/rat.lua"
    Entities[1] = Entity;

    local Entity = {};
    Entity.nombre = "wolf";
    Entity.script = "/home/ronald/ClionProjects/engine/scripts/wolf.lua"
    Entities[2] = Entity;

    Entities.size = #Entities;

end
