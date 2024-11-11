def main():
    t=int(input())
    all_input=[]
    for i in range(t):
        n=int(input())
        if n==1:
            print(-1)
        else:
            string_ans='2'
            for j in range(n):
                string_ans+='3'
            print(string_ans)

# print(main())
main()