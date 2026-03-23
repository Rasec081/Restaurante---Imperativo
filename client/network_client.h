//
// Created by Daniel on 22/3/2026.
//

#ifndef IMPERATIVO_NETWORK_CLIENT_H
#define IMPERATIVO_NETWORK_CLIENT_H

#include <nlohmann/json.hpp>

using json = nlohmann::json;

void initConnection();
void sendJSON(json request);

#endif //IMPERATIVO_NETWORK_CLIENT_H