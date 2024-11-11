def main():
    testCases = int(input())
    for i in range(testCases):
        n = int(input())
        stack=[]
        demoString=input()
        index=0
        count=0
        for index in range(n):
            if(demoString[index]=='('):
                stack.append('(')
            elif((demoString[index]==')') and (len(stack)==0)):
                count=count+1
            elif(demoString[index]==')' and stack.pop()=='('):
                pass
    print(count)


if __name__ == "__main__":
    main()