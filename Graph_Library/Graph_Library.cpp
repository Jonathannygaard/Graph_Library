#include <iostream>
#include <vector>
#include <list>

class Edge_Node;
class Graph_Node;
std::vector<int> Vector;

class Graph_Node
{
public:
    int data;
    std::vector<Edge_Node*> Edges;
    std::vector<Graph_Node*> Adjacent_Nodes;
    bool Visited = false;
};
class Edge_Node
{
public:
    int Weight;
    std::vector<Graph_Node*> Nodes;
    bool Visited = false;
};

class Graph
{
public:
    std::vector<Graph_Node*> All_Nodes;
    std::vector<Edge_Node*> All_Edges;
    Graph_Node* root;
    Edge_Node* temp_edge;

    /// \brief Creating a new graph node
    /// \param data Information to be stored in node (int)
   Graph_Node* new_graph_node(int data)
    {
        Graph_Node* node = new Graph_Node();
        All_Nodes.push_back(node);
        node->data = data;
        return node;
    }

    /// \brief Creating a new edge
    /// \param Weight Weight of node (int)
    Edge_Node* new_edge_node(int Weight)
    {
        Edge_Node* node = new Edge_Node();
        All_Edges.push_back(node);
        node->Weight = Weight;
        return node;
    }

    /// \brief Connecting two node and creating an edge between them
    /// \param Node First node to connect
    /// \param Node2 Second node to connect
    /// \param Weight Weight of Edge
    void connect_nodes(Graph_Node* Node, Graph_Node* Node2, int Weight)
   {
       std::vector<Graph_Node*> Nodes;
         Nodes.push_back(Node);
         Nodes.push_back(Node2);
       Edge_Node* Edge = new_edge_node(Weight);
       Edge->Nodes = Nodes;
       Node->Adjacent_Nodes.push_back(Node2);
       Node2->Adjacent_Nodes.push_back(Node);
       Node->Edges.push_back(Edge);
       Node2->Edges.push_back(Edge);
   }

    /// \brief Removing connection between two nodes
    /// \param Node First node to remove connection from
    /// \param Node2 Second node to remove connection from
    void remove_connection(Graph_Node* Node, Graph_Node* Node2)
   {
         for (auto Edge : Node->Edges)
         {
              for (auto check_Node: Edge->Nodes)
              {
                  if(check_Node != Node2)
                  {
                      continue;
                  }
                  for (auto Node: Edge->Nodes)
                  {
                      Edge->Nodes.erase(Edge->Nodes.begin());
                      temp_edge = Edge;
                  }
              }
         }

       for(size_t i; i < All_Edges.size()-1; i++)
       {
           if(temp_edge == All_Edges[0])
           {
               All_Edges.erase(All_Edges.begin());
               return;
           }
           All_Edges.push_back(All_Edges.front());
           All_Edges.erase(All_Edges.begin());
       }
       
          for(int i = 0; i < Node->Adjacent_Nodes.size()-1; i++)
          {
                if(Node->Adjacent_Nodes[i] == Node2)
                {
                 Node->Adjacent_Nodes.erase(Node->Adjacent_Nodes.begin() + i);
                }
          }
          for(int i = 0; i < Node2->Adjacent_Nodes.size()-1; i++)
          {
                if(Node2->Adjacent_Nodes[i] == Node)
                {
                 Node2->Adjacent_Nodes.erase(Node2->Adjacent_Nodes.begin() + i);
                }
          }
       if(Node->Edges.empty())
       {
           if(Node->Adjacent_Nodes.empty())
           {
               delete Node;
           }
       }
       if(Node2->Edges.empty())
       {
           if(Node2->Adjacent_Nodes.empty())
           {
               delete Node2;
           }
       }
     }
    
     /// \brief Finding all nodes connected to a node
     /// \param Node Node to find adjacent nodes of
     void find_adjacent_nodes(Graph_Node* Node)
    {
         for (auto node: Node->Adjacent_Nodes)
         {
              std::cout<<node->data<<std::endl;
         }
    }
    
     /// \brief Finding all edges connected to a node
     /// \param Node Node to find edges of
     void find_edges(Graph_Node* Node)
    {
         for (auto edge: Node->Edges)
         {
              std::cout<<edge->Weight<<std::endl;
         }
   }

    /// \brief Counting all nodes in graph
    /// \param Graph Graph to find nodes of
    int find_size(Graph* Graph)
    {
        return Graph->All_Nodes.size();
    }

    /// \brief Counting all edges in graph
    /// \param Graph Graph to find edges of
    int find_size_of_edges(Graph* Graph)
    {
        return Graph->All_Edges.size();
    }

    /// \brief Finding amount of adjacent nodes of node
    /// \param Node Node to find adjacent nodes of
    int find_amount_of_adjacent_nodes(Graph_Node* Node)
    {
        return Node->Adjacent_Nodes.size();
    }

    /// \brief Finding amount of edges of node
    /// \param Node Node to find edges of
    int find_amount_of_edges_of_node(Graph_Node* Node)
    {
        return Node->Edges.size();
    }

    /// \brief Finding data of node
    /// \param Node Node to find data of
    int find_data_of_node(Graph_Node* Node)
   {
       return Node->data;
   }

    /// \brief Finding Weight of an Edge
    /// \param Edge Edge to find weight of
    int find_weight_of_edge(Edge_Node* Edge)
   {
       return Edge->Weight;
   }

    /// \brief Finding a random node
    Graph_Node* find_random_node()
   {
       return All_Nodes[rand() % All_Nodes.size() - 1];
   }

    /// \brief Creating a node connected to a random node from your graph
    /// \param data Data Node should hold
    /// \param weight Weight of edge between Nodes
    void create_node_randomly(int data, int weight)
   {
       connect_nodes(find_random_node(), new_graph_node(data), weight);
   }

    /// \brief Printing all nodes using depth first search
    /// \param root Node to start printing from
    void print_graph(Graph_Node* root)
    {
       bool to_continue = false;
       int temp_visited_check = 0;
       for (auto node: All_Nodes)
       {
           if(node->Visited== true)
           {
               temp_visited_check++;
           }
       }
       if(temp_visited_check == All_Nodes.size())
       {
        return;
       }
       for(auto edge: root->Edges)
       {
           if(edge->Visited == true)
           {
               continue;
           }
           for (auto node: edge->Nodes)
           {
               if(node == root)
               {
                   continue;
               }
               if(node->Visited == true)
               {
                   to_continue = true;
               }
           }
           if(to_continue == true)
           {
               continue;
           }
           for(auto node: edge->Nodes)
           {
               if(node == root)
               {
                   continue;
               }
               std::cout<<root->data;
               root->Visited = true;
               std::cout << "----" << edge->Weight << "----";
               edge->Visited = true;
               std::cout<<node->data<<std::endl;
               node->Visited = true;
               
               print_graph(node);
           }
       }
    }
};

int main(int argc, char* argv[])
{
    Graph Graph;
    Graph.root = Graph.new_graph_node(1);
    Graph.connect_nodes(Graph.root, Graph.new_graph_node(2), 5);
    Graph.connect_nodes(Graph.root, Graph.new_graph_node(3), 10);
    Graph.connect_nodes(Graph.root->Adjacent_Nodes[0], Graph.new_graph_node(4), 6);
    Graph.connect_nodes(Graph.root->Adjacent_Nodes[0], Graph.new_graph_node(5), 11);
    Graph.connect_nodes(Graph.root->Adjacent_Nodes[0]->Adjacent_Nodes[1], Graph.root->Adjacent_Nodes[1], 8);
    Graph.create_node_randomly(6,10);

    //Graph.remove_connection(Graph.root->Adjacent_Nodes[1],Graph.root->Adjacent_Nodes[0]->Adjacent_Nodes[1]);
    Graph.print_graph(Graph.root);
    return 0;
}
