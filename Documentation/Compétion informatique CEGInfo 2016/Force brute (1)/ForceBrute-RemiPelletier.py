#Auteur:   Rémi Pelletier
#Fichier:  ForceBrute-RemiPelletier.py
#Problème: Force brute (Compétition informatique CEGInfo-CEGL 2016)
#Score:    45.45/50 (le dernier test échoue en raison d'un timeout)

import re

class Node:
    value = 0
    nNodes = 1
    childs = []
    
    def __init__(self):
        self.value = 0
        self.nNodes = 1
        self.childs = []

def multiplyRange(start, end):
    result = 1
    for i in range(start, end+1):
        result *= i
    return result

def computeNbTrees(length):
    return multiplyRange(length+2, 2*length) // multiplyRange(1, length)

def getWorstLength(node):
    length = 0
    if len(node.childs) == 0:
        length = 0
    elif len(node.childs) == 1:
        length = node.value + getWorstLength(node.childs[0])
    elif len(node.childs) == 2:
        length = node.value + max(getWorstLength(node.childs[0]), getWorstLength(node.childs[1]))
    return length

def readNode(line, curIndex):
    curNode = Node()
    while (curIndex[0] < len(line)) and (line[curIndex[0]] != ')'):
        c = line[curIndex[0]]
        curIndex[0] += 1
        if c == '(':
            curNode.childs.append(readNode(line, curIndex))
        elif c == '.':
            subStr = re.search(r'\d+', line[curIndex[0]:]).group()
            curNode.value = int(subStr)
            curIndex[0] += len(subStr) + 1
            
    if(line[curIndex[0]] == ')'):
        curIndex[0] += 1
       
    for j in range(0, len(curNode.childs)):
        curNode.nNodes += curNode.childs[j].nNodes
       
    return curNode


line = input()
curIndex = [1]
curIndex[0] = 1
root = readNode(line, curIndex)
print(int(getWorstLength(root)))
print((computeNbTrees(root.nNodes)))
