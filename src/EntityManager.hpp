#pragma once
#include "Entity.hpp"
#include <map>
#include <memory>
#include <vector>

typedef std::vector<std::shared_ptr<Entity>> entityVec;
typedef std::map<std::string, entityVec> entityMap;

class EntityManager {
	entityVec m_entities;
	entityVec m_entitiesToAdd;
	entityMap m_entitiesMap;
	size_t m_totalEntities = 0;

	void removeDeadEntities(entityVec& vec);

public:
	EntityManager();

	void update();
	std::shared_ptr<Entity> addEntity(const std::string& tag);
	const entityVec& getEntities();
	const entityVec& getEntities(const std::string& tag);
};