int DeleteQueue(SeqQueue *Q, int *x);   //出队
int PopStack(SeqStack *S, int *x);   //出栈


int Judge(SeqQueue *Q, SeqStack *S)
{
    int counter = 0;
    int x, y;
    while (1)
    {
        PopStack(S, &x);  //出栈
        DeleteQueue(Q, &y);  //出队
        if (x != y)
        {
            cout << "不是回文" << endl;
            return -1;
        }
        counter++;
        if (counter >= S->top / 2)
        {
            cout << "是回文" << endl;
            return 0;
        }
    }
}

//进栈/队顺序  1 2 3 4 5 6
//Stack        1 2 3|3 2 1 ->
//Queue     <- 1 2 3|3 2 1


//进栈/队顺序  1 2 3 4 5 6
//Stack        1 2 3|5 6 7 ->
//Queue     <- 1 2 3|5 6 7