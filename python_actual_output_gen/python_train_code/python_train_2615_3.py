# import sys
# sys.stdin=open('input.in','r')
# sys.stdout=open('output.out','w')

n=int(input())
k=0

def moves(l,k):   
    while l[0]>0:

    	k+=l[0]%l[1] 

    	# k+=1  	
    	l[0]=l[0]//l[1]
    	if l[0]>=2:
    		k+=1
    	
    	
    
    return k
       
    
    
for i in range(n):
    print(moves(list(map(int,input().split(' '))),k))