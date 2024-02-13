#include "entity_manager.h"

EntityManager::EntityManager()
{
}


void EntityManager::update()
{
    // add entities from m_entitiesToAdd to m_entities
    // add them to the vector inside the map, with the corresponding tag


    // remove dead entities from the vector
    removeDeadEntities(m_entities);

    for(auto& [tag, entityVec] : m_entityMap)
    {
        for(auto& entity : entityVec)
        {
            removeDeadEntities(entityVec);
        }
    }

}

void EntityManager::removeDeadEntities(EntityVec& vec)
{
    // TODO remove all dead entities from the input vector
    // filter all that are dead and then remove them one by one
}

std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
    auto entity = std::shared_ptr<Entity>(new Entity(m_totalEntities++, tag));

    m_entitiesToAdd.push_back(entity);

    return entity;
}

const EntityVec& EntityManager::getEntities()
{
    return m_entities;
}

const EntityVec& EntityManager::getEntities(const std::string& tag)
{
    return m_entityMap[tag];
}

const std::map<std::string, EntityVec>& EntityManager::getEntityMap()
{
    return m_entityMap;
}
