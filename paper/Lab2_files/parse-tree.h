#ifndef __PARSE_TREE_H__
#define __PARSE_TREE_H__

/**
 * parse-tree.h
 *   ��������� ������ ��� ������ �������.
 *
 */

// +-------------+
// | ����������� |
// +-------------+

/*
  �� ������������ ���� � �������������� ������������ ��� ���� C ���������.
  ������ ������ ���������� � ������ ����� - ���� ����. ������ ��� ������������
  ��������� �������, ������, �.�. � ��� ����� ���� �����, �� ������������
  ���������������� �����. ����� ��������� ������ �� ������� �������
  ��� ���������� �������� �����. ��� �������� ����� ������� � ������� �������.
  ������������ �������������� ����� ��������� ��������.  ��������� �������� C
  �������, ��� �������� �������� �����������, �� �������� ������� �����������
  ������, �� �����������, ��� ��� ���� ����� ����������� ������.
 */


#include <stdio.h>
#include "attribute.h"


/**
 * � ����������� ����� ���� ��� (��� ��������), ������ (��������
 * ��� ����������) � ����� ���������.
 */        
extern int TYPE_NODE;
typedef struct Node
{
    int type;
    int symbol;
    AttributeSet* attributes;
} Node;

/**
 * � �����, ���������� ���������/������� ��� �������������� ����������.
 * ��� �� �����, �������������� ��������� ��� ��� �������.
 */
extern int TYPE_TNODE;
typedef struct TNode
{
    Node parent;
} TNode;

/**
 * ����, ���������� �����������, ����� ����� ����� ������ ��������.
 */
extern int TYPE_NNODE;
typedef struct NNode
{
    Node parent;
    int arity;          // ���������� ������ ��������
    Node** children;    // ����������
} NNode;


// +-------------------+
// | ��������� ������� |
// +-------------------+

/**
 * ������������ ������, ������� ��� ������ �������.
 */
void FreeTree(Node* tree);

/**
 * ��������� ������� ����� ������.
 */
int GetNodeArity(Node* tree);

/*
 * ��������� i-�� ��������� ��������� ������.
 */
Node* GetNodeChild(Node* tree, int i);

/**
 * �������� �� ���� ������������ (NNode).
 */
int IsNonterminalNode(Node* tree);

/**
 * �������� �� ���� ���������� (TNode).
 */
int IsTerminalNode(Node* tree);

/**
 * ������� ����� �������������� ����, ������� �������� �������� ����������.
 * ���������� ���� � ������ ������ � NULL � ��������� ������.
 */
Node* CreateNonterminalNode(int nonterm, int arity, AttributeSet* attributes);

/**
 * ������� ����� ������������ ����, ������� �������� �������� ����������.
 * ���������� ���� � ������ ������ � NULL � ��������� ������.
 */
Node* CreateTerminalNode(int term, AttributeSet* attributes);

/** 
 * �������� ������ � �������� �����.
 */
void PrintTree(FILE* stream, Node* node);

/**
 * ������ i-�� ������� ���� ������. 
 * ���������� 1 � ������ ������ � 0 � ��������� ������.
 */
int SetNodeChild(Node* node, int i, Node* child);

#endif