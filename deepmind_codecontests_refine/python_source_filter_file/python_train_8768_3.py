from sys import stdin
import sys, threading

 
def Soln(node, parent, depth, depthArr, treeArr, sizeArr):
    depthArr[node] = depth
    sizeArr[node] = 1
   
    for child in treeArr[node]:
        if child != parent:
            sizeArr[node] += Soln(child, node, depth + 1, depthArr, treeArr, sizeArr)
            
    return sizeArr[node]
 

def main():
    n, k = list(map(int, stdin.readline().rstrip().split(" ")))
    
    happinessArr = [0] * n
    treeArr = [[] for i in range(n + 1)]
    depthArr = [0] * (n + 1)
    sizeArr = [0] * (n + 1)
    
    for _ in range(n - 1):
        x, y = map(int, input().rstrip().split(" "))
        treeArr[x].append(y)
        treeArr[y].append(x)
    
    Soln(1, -1, 0, depthArr, treeArr, sizeArr)
    
    for i in range(n):
        happinessArr[i] = sizeArr[i + 1] - 1 - depthArr[i + 1]
    
    happinessArr = sorted(happinessArr, reverse=True)
    happiness = 0
    for i in range(n - k):
        happiness += happinessArr[i]
    
    print(happiness)


if __name__ == "__main__":
    sys.setrecursionlimit(2 * (10 ** 5) + 1)
    threading.stack_size(10240000)
    thread = threading.Thread(target=main)
    thread.start()
