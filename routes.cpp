#include "crow_all.h"

crow::response greet()
{
    return crow::response{"Hello world!"};
}

crow::response add(const crow::request &req)
{
    auto input = crow::json::load(req.body);
    if (!input)
    {
        return crow::response(400, "Invalid JSON");
    }

    double first = input["first"].d();
    double second = input["second"].d();
    double result = first + second;

    crow::json::wvalue response;
    response["result"] = result;

    return crow::response{response};
}

crow::response subtract(const crow::request &req)
{
    auto input = crow::json::load(req.body);
    if (!input)
    {
        return crow::response(400, "Invalid JSON");
    }
    double first = input["first"].d();
    double second = input["second"].d();
    double result = first - second;

    crow::json::wvalue response;
    response["result"] = result;

    return crow::response{response};
}