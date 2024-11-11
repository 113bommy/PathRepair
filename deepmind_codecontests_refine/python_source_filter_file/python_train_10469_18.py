def main():
    name=input()
    alphabet='abcdefghijklmnopqrstuvwxyz'
    current='a'
    result=0
    for i in range(len(name)):
        dist=abs(alphabet.find(current)-alphabet.find(name[i]))
        result+=min((dist,26-dist))
        current=name[i]
    print(name, result)
if __name__ == "__main__":
    main()
        