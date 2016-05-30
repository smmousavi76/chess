#include "Parser.hpp"
#include <iostream>

using namespace std;
/*
string Parser::removespace(string str)
{
    string test = "";
    for(unsigned int i=0;i<str.length();i++)
    {
        if(str[i]!= ' ')
            test +=str[i];
    }
    return test;
}

string Parser::currentSelect(string& remainedJson)
{
    string tmp;
    string tmp2 = "";
    for(unsigned int i=0;i<remainedJson.length();i++)
    {
        if(remainedJson[i]=='{')
        {
            for(int j=remainedJson.length()-1;j>=0;j--)
                if(remainedJson[j]=='}')
                {
                    tmp =  remainedJson.substr(i+1,j-i-1);
                    tmp2.append(remainedJson.substr(0,i));
                    tmp2.append(remainedJson.substr(j-i+1));
                    remainedJson = tmp2;
                    return tmp;
                }
        }
    }
    return "";
}

string Parser::typeSpecifier(string& str)
{
    string tmp;
    string tmp2;
    for(unsigned int i=0;i<str.length();i++)
    {
        if(str[i]=='"')
        {
            for(unsigned int j=i+1;j<str.length();j++)
            {
                if(str[j]=='"')
                {
                    tmp = str.substr(i+1,j-i-1);
                    tmp2.append(str.substr(0,i));
                    tmp2.append(str.substr(j-i+2));
                    str = tmp2;
                    return tmp;
                }
            }
        }
    }
    return "";
}

string Parser::dataSpecifier(string& str)
{
    string tmp;
    string tmp2;
    int i=0;
    for(unsigned int j=i+1;j<str.length();j++)
    {
        if(str[j]==',')
        {
            tmp = str.substr(i,j-i);
            tmp2.append(str.substr(0,i));
            if(j-i+2<str.length()-1)
                tmp2.append(str.substr(j-i+1));
            str = tmp2;
            return tmp;
        }
    }
    tmp = str;
    str = "";
    return tmp;
}

string Parser::firstOfList(string& str)
{
    string tmp;
    string tmp2;
    for(unsigned int i=0;i<str.length();i++)
    {
        if(str[i]=='{')
        {
            for(unsigned int j=i+1;j<str.length();j++)
            {
                if(str[j]=='}')
                {
                    tmp = str.substr(i+1,j-i-1);
                    tmp2.append(str.substr(0,i));
                    if(j-i+2<str.length()-1)
                        tmp2.append(str.substr(j-i+3));
                    else
                        tmp2.append(str.substr(j-i+2));
                    str = tmp2;
                    return tmp;
                }
            }
        }
    }
    return "";
}

string Parser::firstOfList2(string& str)
{
    string tmp;
    string tmp2;
    for(unsigned int i=0;i<str.length();i++)
    {
        if(str[i]=='[')
        {
            for(unsigned int j=i+1;j<str.length();j++)
            {
                if(str[j] ==',' || str[j]==']')
                {
                    tmp = str.substr(i+1,j-i-1);
                    tmp2.append(str.substr(0,i+1));
                    if(j-i<str.length()-1)
                        tmp2.append(str.substr(j-i+1));
                    else
                        tmp2.append(str.substr(j-i));
                    str = tmp2;
                    return tmp;
                }
            }
        }
    }
    return "";
}

string Parser::_(string& str)
{
    string tmp;
    string tmp2;
    for(unsigned int i=0;i<str.length();i++)
    {
        if(str[i]=='[')
        {
            for(unsigned int j=i+1;j<str.length();j++)
            {
                if(str[j]==']')
                {
                    tmp = str.substr(i,j-i+1);
                    tmp2.append(str.substr(0,i));
                    if(j-i+2<str.length()-1)
                        tmp2.append(str.substr(j-i+2));
                    else
                        tmp2.append(str.substr(j-i+1));
                    str = tmp2;
                    return tmp;
                }
            }
        }
    }
    return "";
}

Graph* Parser::read(string remainedJson)
{
    Graph* graph = new Graph;
    remainedJson = removespace(remainedJson);
    string currentJson = currentSelect(remainedJson);
    //cout <<currentJson;
    string type;
    type = typeSpecifier(currentJson);
    string secondLayer = _(currentJson);
    string data;
    if(type == "nodes")
    {
        while (secondLayer[0] != '[' || secondLayer[1] != ']')
        {
            data = firstOfList(secondLayer);
            int index, color;
            bool type;
            for(unsigned int i=0;i<3;i++)
            {
                string tmp = typeSpecifier(data);
                if(tmp == "index")
                {
                    index = stoi(dataSpecifier(data));
                }
                if(tmp == "color")
                {
                    color = stoi(dataSpecifier(data));
                }
                if(tmp == "type")
                {
                    type = stoi(dataSpecifier(data));
                }
            }
            graph->nodes.push_back(new Node(index,color,type));
        }
    }
    while(currentJson != "")
    {
        type = typeSpecifier(currentJson);
        secondLayer = _(currentJson);
        if(type != "nodes")
        {
            int index = stoi(type)-1;
            while (secondLayer[0] != '[' || secondLayer[1] != ']')
            {
                string dstIndex = firstOfList2(secondLayer);
                string weight = firstOfList2(secondLayer);
                graph->nodes[index]->addAdjNode(graph->nodes[stoi(dstIndex)-1],stoi(weight));
            }
        }
    }
    return graph;
}

string Parser::write(Node* node)
{
    string tmp = "";
    tmp += "{";
    tmp += "\"index\":" + std::to_string(node->getIndex());
    tmp += ",";
    tmp += "\"type\":" + std::to_string(node->getType());
    tmp += ",";
    tmp += "\"color\":" + std::to_string(node->getColor());
    tmp += "}";
    return tmp;
}

string Parser::write(QList<Edge*> edges)
{
    string tmp = "[";

    for(Edge* edge : edges)
    {
        tmp += to_string(edge->getDstNode()->getIndex());
        tmp += ",";
        tmp += to_string(edge->getCost());
        tmp += ",";
    }
    if(tmp.back() == ',')
        tmp.back() = ']';
    else
        tmp += "]";
    return tmp;
}

string Parser::write(Graph* graph)
{
    string tmp = "";
    tmp += "{";
    tmp += "\"nodes\":[";
    for(Node* node : graph->nodes)
    {
        tmp += write(node);
        tmp +=",";
    }
    tmp[tmp.length()-1] = ']';
    tmp += ",";
    for(Node* node : graph->nodes)
    {
        tmp += "\"" + to_string(node->getIndex()) + "\":";
        tmp += write(node->getAdjNodeList());
        tmp +=",";
    }
    tmp.back() = '}';
    return tmp;
}
*/
