num=int(input())
heights=list(map(int, input().split()))

def find_index_smallest(list):
    i = 0
    for x in range(0,len(list)):
        if list[x] < list[i]:
            i=x
    return i

def swap(list,i):
    tmp=list[i+1]
    list[i+1]=list[i]
    list[i]=tmp

def main(num,heights):
    output=[]
    for x in range(0,num):
        s=find_index_smallest(heights[x:])
        s=s+x
        while s>x:
            swap(heights,s-1)
            output.append((s-1,s))
            s=s-1
    return output

def pretty_print(seq):
    for (a,b) in seq:
        print(a," ",b)

seq=main(num,heights)

pretty_print(seq)

