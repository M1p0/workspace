struct  node
{
    int Data;
    node *Next;
};

class Link
{
private:

public:
    node *head;
    Link() { head = NULL; }
    void Insert(int value);
    void Delete_Value(int value);
    void Delete_Pos(int pos);
    void Output();
    void Set_Loop(int start, int end);
    void Check_Loop();
    int  Length();

    


};