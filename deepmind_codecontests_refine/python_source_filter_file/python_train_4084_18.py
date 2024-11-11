from sys import stdin, stdout
 
def main():
    n = int(stdin.readline())
    arr = list(map(int, stdin.readline().split()))
    pow2 = [0] * 32
    max = 0
    ans = [0] * 32
    for j,i in enumerate(arr):
        x = int(i)
        z = 0
        while x > 0:
            if (x - pow(2,z)) % pow(2,z+1) == 0:
                x -= pow(2,z)
                pow2[z]+= 1
                if pow2[z] == 1:
                    ans[z] = j
            z += 1
    for i,x in enumerate(pow2):
        if x == 1:
            max = i
 
    if pow2[max] == 1:
        arr[0], arr[ans[max]] = arr[ans[max]], arr[0]
    
    stdout.write(" ".join(str(x) for x in arr))
    
            
        