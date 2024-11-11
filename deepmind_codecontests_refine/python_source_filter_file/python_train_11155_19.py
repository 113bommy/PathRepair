# -*- coding: utf-8 -*-
"""
1 circle
2 triangle
3 square
"""
def convert(string):
    return string.split(sep=None,maxsplit=-1)

def toint(lst):
    result=[]
    for i in lst:
        result.append(int(i))
    return result

n=int(input())
temp=toint(convert(input()))
count=0
measure="finite"

for i in range(n-1):
    first=temp[i]
    second=temp[i+1]
    pair=(first,second)
    if pair == (1,2):
        try:
            if temp[i-1]==3:
                count+=2
            else:
                count+=3
        except:
            count+=3
    elif pair==(3,1):
        count+=4
    elif pair==(2,1):
        count+=3
    elif pair==(1,3):
        count+=4
    else:
        measure="Infinte"
        break
    
print(measure)
if measure=="Finite":
    print(count)

        
        
        