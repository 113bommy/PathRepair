def maxnum(inputdata):
    inputdata = inputdata[1:]
    k,n,m = 0,0,0
    for i in inputdata:
        if i == '9':
            m += 1
        if i == '8':
            m+=1
    if m == len(inputdata):
        return(inputdata)
    if int(inputdata) < int('9'*(len(inputdata)-1) + '8'):
        for i in inputdata:
            if i == '9':
                n += 1
            else: 
                break
                n -= 1
        str2 = inputdata[:(n-1)] + '8' + '9'*(len(inputdata)-(n))
    else: 
        str2 = inputdata
    return(str2)
inputdata = input()
if inputdata[0] == '0':
  h = '0'
else : 
  h = inputdata[1::]
  if int(inputdata) > 10:
      if int(h) < int('8'+'9'*(len(h)-1)):
          h = str((int(inputdata[0])-1)) + '9'*len(h)
      else:
          h = inputdata[0] + maxnum(inputdata)
  else:
       h = inputdata
  if h[0] == '0':
      h = h[1:]
print(h)