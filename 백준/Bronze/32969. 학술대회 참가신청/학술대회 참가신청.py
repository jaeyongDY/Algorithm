rally = {"digital humanities" : ["social", "history", "language", "literacy"], "public bigdata" : ["bigdata", "public", "society"]}

n = input()

n = n.split(" ")

find = False

for key,value in rally.items() :
    for data in n :
        if data in value :
            find = True
            print(key)
            break
    if find :
        break