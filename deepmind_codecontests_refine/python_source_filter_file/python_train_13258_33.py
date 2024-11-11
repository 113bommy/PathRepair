def main():
  s,n=map(int,input().split())
  liss=[list(map(int,input().split())) for  i in range(n)]
  for i in range(n):
    s+=liss[i][1]
  liss.sort(reverse=True)
  for i in range(n):
    s-=liss[i][1]
    if s<liss[i][0]:
        print("NO")
        return
  print("YES")

if __name__ == '__main__':
    main()
