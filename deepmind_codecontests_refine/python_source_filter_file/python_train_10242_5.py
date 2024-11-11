
def solve(i, j, lights): 
    lights[i][j] ^= 1
    pos = [(i+1,j),(i-1,j),(i, j+1),(i,j-1)]
    for val in pos:
        i, j = val
        if 0 <= i < 3 and 0 <=j and j <3:
            lights[i][j] ^= 1
            
def main():
    m = n = 3
    a = []
    lights = [[1 for x in range(m)] for y in range(n)]
    for i in range(3):
        a.append([int(x) for x in input().split()])
        for j in range(3):
            if a[i][j] % 2:
                solve(i, j, lights)
    for row in lights:
        print (' '.join([str(x) for x in row]))
    
main()    