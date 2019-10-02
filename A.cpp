#include <stdio.h>
//#ifndef APATH_H
#include "Apath.h"
//#endif

//Ϊ�򵥣��ɴ�Ѱ���������תΪ����ṹ������
//Լ����0�ǿ��ߵģ�1��ʾ�ϰ��ﲻ���ߣ�2��ʾ��㣬3��ʾ�յ㣬4��ʾ·��
int array[10][10] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 1, 3, 0, 0, 0 },
    { 0, 0, 2, 0, 0, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 1, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

int main()
{
    int row = MAP_MAX_X, col = MAP_MAX_Y;
    printf("hello world!\n");
    LNode **map = Translate_array(array,row, col); //���ｫ����ĵ�ͼתΪ�ڵ�map�ĵ�ͼ
    output(map,10,10);
    LinkList open_List = InitList();     //���岢��ʼ��һ�������б�
    LinkList close_List = InitList();    //һ������б�
    LNode* startLNode = find_start_LNode(map, row, col);
    LNode* endLNode = find_end_LNode(map, row, col);

    LNode* curLNode = startLNode;        //��ǰ�ڵ�=��ʼ�ڵ�
    curLNode->G = 0;        //����ڵ������ֵ
    count_LNode_H(curLNode, endLNode);
    count_LNode_F(curLNode);
    push_OpenList_Node(open_List, curLNode);        //�Ƚ���ʼ�ڵ���뿪���б�

    while (curLNode->data != 3)
    {
        //LNode *e = NULL;
        curLNode = pop_OpenList_minNode(open_List);
        insert_Into_CloseList(curLNode, close_List);
        //2���鿴�����Χ�ĵ��Ƿ��ڿ����б�����ڼ��룬�ڼ�⾭���õ�Fֵ�Ƿ���С�ȣ�
        check_around_curNode(curLNode, endLNode, open_List, map);
    }
    while (endLNode->path_next)
    {
        printf("x:%d---y:%d\n", endLNode->path_next->x,endLNode->path_next->y);
        endLNode->path_next = endLNode->path_next->path_next;
    }
    return 0;
}

main.c
