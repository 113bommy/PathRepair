t = int(input())
arr = input()   
l = list(map(int,arr.split(' ')))  
print(l)
residue = 0
for num in l :
    residue += (max(l))-num
print(residue)    