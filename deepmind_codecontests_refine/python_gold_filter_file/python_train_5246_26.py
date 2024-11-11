

if __name__ == '__main__':
   n = int(input())
   s = input()
   st,t = -1,-1
   if s.find('R') == -1:
       print(s.rfind('L')+1,s.find('L'))
       exit()
   if s.find('L') == -1:
       print(s.find('R')+1,s.rfind('R')+2)
       exit()
   for i in range(len(s)-1):
       if s[i] == 'R' and st == -1:
           st = i
       if s[i] == 'R' and s[i+1] == 'L':
           t = i+1
   print(st+1,t+1)



