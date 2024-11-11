def main():
  a=int(input())
  for i in range(a):
    b=int(input())
    if(b%2==0 and b>2):
      print(int((b/2)-1))
      continue
    elif(b%2!=0 and b>2):
      print(int(b-1)/2)
      continue
    elif(b==2 or b==1 or b==0):
      print("0")
      continue


if __name__ == "__main__": 
  main()
  