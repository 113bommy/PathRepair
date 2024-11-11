# import sys 
# sys.stdin = open('input.txt', 'r')  
# sys.stdout = open('output.txt', 'w') 

s=input()
c=s.count('a')
print(min(len(s),c+1))
