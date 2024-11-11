n,h= input().split(' ')
n=int(n)
h=int(h)
heights=[int(x) for x in input().strip().split(' ')]

def solution(no_friends,max_height,Heights):
    count = 0
    if no_friends>=1:
        for i in range(no_friends):
            count+=1
            if (Heights[i]>=max_height):
                count+=1
        return count        
        
print (solution(n,h,heights))