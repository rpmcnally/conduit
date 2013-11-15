///
/// file: Node.h
///


#include "Core.h"
#include "Type.h"
#include <map>
#include <vector>
#include <string>

namespace conduit
{

class Node
{
public:
    Node(); // empty node
    Node(const Node &node);
    Node(const BaseType &dtype);
    Node(void *data, const std::string &schema);
    Node(void *data, const Node *schema);
    Node(void *data, const BaseType &dtype);

    Node(BaseType dtype);
    Node(uint32  data);
    Node(float64 data);

    Node(const std::vector<uint32>  &data);
    Node(const std::vector<float64>  &data);

    virtual  ~Node();

    void set(const Node& data);
    void set(BaseType data);

    void set(uint32 data);
    void set(float64 data);

    void set(const std::vector<uint32>  &data);
    void set(const std::vector<float64> &data);

    void set(void* data, const Node* schema);
    void set(void* data, const BaseType &dtype);

    Node &operator=(const Node &node);

    Node &operator=(BaseType dtype);

    Node &operator=(uint32 data);
    Node &operator=(float64 data);

    Node &operator=(const std::vector<uint32>  &data);
    Node &operator=(const std::vector<float64>  &data);


    std::string schema() const;

    const BaseType    &dtype() const { return *m_dtype;}
    // bool              operator==(const Node &obj) const;
    // TODO: we will likly need const variants of these methods

    Node             &fetch(const std::string &path);
    bool             has_path(const std::string &path) const;
    void             paths(std::vector<std::string> &paths,bool expand=false) const;

    Node             &operator[](const std::string &path)
                      {return fetch(path);}

    index_t          to_integer() const;
    float64          to_real()    const;

    uint32           as_uint32()  const { return *((uint32*)element_pointer(0));}
    float64          as_float64() const { return *((float64*)element_pointer(0));}

    uint32          *as_uint32_ptr()   { return (uint32*)element_pointer(0);}
    float64         *as_float64_ptr()  { return (float64*)element_pointer(0);}
    
    
//    List             as_list();

    
private:
    void             init(const BaseType &dtype);
    void             init(const ValueType &dtype);
    void             cleanup(); //dalloc 
    

    // for value types
    index_t          element_index(index_t   idx) const;
    void            *element_pointer(index_t idx)
                     {return static_cast<char*>(m_data) + element_index(idx);};
    const void      *element_pointer(index_t idx) const 
                     {return static_cast<char*>(m_data) + element_index(idx);};

    // for true nodes
    std::map<std::string, Node> &entries();

    std::map<std::string, Node> m_entries;
    bool      m_alloced;
    void     *m_data;
    BaseType *m_dtype;
    
};

};
