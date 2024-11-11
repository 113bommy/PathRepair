def triangulate(n):
    if n <= 2:
        return 1
    return 1*(n-1)*(n) + triangulate(n-1)
    
    
print(triangulate(int(input())))