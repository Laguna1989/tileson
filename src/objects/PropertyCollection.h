//
// Created by robin on 02.08.2019.
//

#ifndef TILESON_PROPERTYCOLLECTION_H
#define TILESON_PROPERTYCOLLECTION_H

#include "Property.h"
#include <map>

namespace tson
{
    class PropertyCollection
    {
        public:
            PropertyCollection() = default;

            explicit PropertyCollection(std::string id);

            tson::Property * add(const tson::Property &property);
            tson::Property * add(const std::string &name);
            tson::Property * add(const std::string &name, const std::any &value);

            void remove(const std::string &name);

            void setValue(const std::string &name, const std::any &value);
            void setId(const std::string &id);

            bool hasProperty(const std::string &name);
            tson::Property * getProperty(const std::string &name);
            std::map<std::string, Property> &getProperties();
            template <typename T>
            T getValue(const std::string &name);
            const std::string &getId() const;

        protected:
            std::string m_id;
            std::map<std::string, tson::Property> m_properties;
    };
}

template<typename T>
T tson::PropertyCollection::getValue(const std::string &name)
{
    static T defaultT;
    return (m_properties.count(name) > 0) ? m_properties[name].getValue<T>() : defaultT;
}


#endif //TILESON_PROPERTYCOLLECTION_H