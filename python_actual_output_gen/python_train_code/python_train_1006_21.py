'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''
n=int(input(""))
name=[]
for b in range(n):
    name.append(input(""))
for b in range(n):
     if(len(name[b])>=10):
         print(name[b][0]+str(len(name[b])-2)+name[b][-1])
     else:
        print(name[b])
     