def main():
    answer=[]
    test_case=int(input())
    i=0
    while i<test_case:
        find_total_people(answer)
        i+=1
    for person in answer:
        print(person)

def find_total_people(answer_list):
    a,b,c=map(int,input().split(" "))
    d=0
    total=abs(a-b)*2
    ref=total//2
    if (total>a) and (total>b) and (total>c):
        if c <= ref:
            answer_list.append(ref+c)
        elif c>ref:
            answer_list.append(c-ref)
    else:
        answer_list.append(-1)

if __name__=="__main__":
    main()


    