def main():
   number=int(input())
   while number<9000:
      number+=1
      text=str(number)
      if (text[0]!=text[1] and text[0]!=text[2] and text[0]!=text[3] and text[1]!=text[2] and text[1]!=text[3] and text[2]!=text[3]):
         print(number)
         break
         

main()