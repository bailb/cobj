#include<string>
#include<vector>
using namespace std;

typedef enum {

    FIELD_TYPE_INT,
    FIELD_TYPE_FLOAT,
    FIELD_TYPE_STRING,
    FIELD_TYPE_BOOL,
    FIELD_TYPE_OBJECT

}FIELD_TYPE;

struct field_info 
{

    int offset;
    FIELD_TYPE type;
    string name;
    bool islist;
    void *meta_info;

    field_info &operator=(const field_info &field) 
    {
        this->offset = field.offset;
        this->type   = field.type;
        this->islist = field.islist;
        this->meta_info = field.meta_info;
        return *this;
    }

};

class meta_info 
{
    private:
        vector<field_info> mFields;

    public:
        void addField(meta_info* meta, const field_info &field)
        {
            meta->mFields.push_back(field);
        }

        const field_info& getField(int i)
        {
            return mFields[i];
        }

        int getCount()
        {
            return mFields.size();
        }

};


