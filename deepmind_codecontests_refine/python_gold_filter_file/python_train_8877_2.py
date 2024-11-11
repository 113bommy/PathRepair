def solve(arr):
 
    line=arr.split(" ")
    a=int(line[0])
    b=int(line[1])
    c=int(line[2])
    d=int(line[3])
    if a==d or c==b:
        th=a+b
    if b<c or a>d:
        if a+b > c+d:
            th=a+b
        elif a+b < c+d:
            th=c+d
        else:
            th=a+b
 
    return th
 
 
if __name__ == "__main__":
 
    t = int(input())
 
    results = list()
    for _ in range(0, t):
        arr = str(input())
        results.append(solve(arr))
 
    for result in results:
        print(result,"\n")