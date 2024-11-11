"""
/*************************************************************
# by        : mohamd abda alazez hashim                      #
# e-mail    : mohamdmido2011@gmail.com                       #
# problem   : B. Queue at the School                         #
*************************************************************/
"""

I = input().split(' ')
n = int(I[0])
m = int(I[1])
pres =  I[2]  #president's office

o_size = []

for i in range (n):
    rows = list(input())
    o_size.append(rows)

adj = {'.',pres}
for i in range (n):
    for j in range (m):
        if o_size[i][j]==pres:
            if i==0 or j==0 or j==m-1 or i==n-1:
                if i==0 and i==n-1:
                    x=0
                elif i==0:
                    adj.add(o_size[i+1][j])
                elif i==n-1:
                    adj.add(o_size[i-1][j])
                else:
                    adj.add(o_size[i+1][j])
                    adj.add(o_size[i-1][j])
                
                if j==0 and i==m-1:
                    x=0
                elif j==0:
                    adj.add(o_size[i][j+1])
                elif j==m-1:
                    adj.add(o_size[i][j-1])
                else:
                    adj.add(o_size[i][j-1])
                    adj.add(o_size[i][j+1])
            else:
                    adj.add(o_size[i][j-1])
                    adj.add(o_size[i][j+1])
                    adj.add(o_size[i+1][j])
                    adj.add(o_size[i-1][j])
                    

adj.remove('.')
adj.remove(pres) 

print(len(adj))        
