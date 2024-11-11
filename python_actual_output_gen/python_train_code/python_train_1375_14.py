n = int(input())

last = input()
islands = 0

for i in range(2,n+1):
    
    magnit = input()
    
    if magnit == last:
        
        islands += 1
    
    last = magnit

print(islands)