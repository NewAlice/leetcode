testList = [{'id':1, 'title':'t1', 'parent_id':0},
    {'id':2, 'title':'t2', 'parent_id':0},
    {'id':3, 'title':'t1_1', 'parent_id':1},
    {'id':4, 'title':'t1_2', 'parent_id':1},
    {'id':5, 'title':'t1_2_1', 'parent_id':4},
    {'id':6, 'title':'t2_1', 'parent_id':2},
    {'id':7, 'title':'t2_2', 'parent_id':2}]

print('---------------------------------')
list_tree = []
# 重新排序
def list_order(pid, testList):
    for x in testList:
        if pid == x['parent_id']:
            list_tree.append(x)
            list_order(x['id'], testList)
list_order(0,testList)

for x in list_tree:
    print(x['title'])