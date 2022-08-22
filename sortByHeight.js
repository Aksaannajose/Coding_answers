/*Some people are standing in a row in a park. There are trees between them which
cannot be moved. Your task is to rearrange the people by their heights in a nondescending order without moving the trees.
constraints:
●Given row r, 5 ≤ r.length ≤ 15,
●maximum height of the people could be 200.
●Height of the tree is denoted as -1
●[output] Sorted row with all the trees untouched.
Example
For a = [-1, 150, 190, 170, -1, -1, 160, 180], the output should be
sortByHeight(a) = [-1, 150, 160, 170, -1, -1, 180, 190]
*/

function sortByHeight(a) {
  let indexArr = []
  let newArr = []
  for(let i = 0; i<a.length;i++){
    if(a[i] === -1){
      indexArr.push(i)
    }else{
      newArr.push(a[i])
    }
  }
  newArr.sort((a,b)=> {return a-b})

  for(let i = 0 ; i< indexArr.length;i++){
    newArr.splice(indexArr[i],0,-1)
  }
  return newArr
}
console.log(sortByHeight([-1, 150, 190, 170, -1, -1, 160, 180]))
console.log(sortByHeight([2, 2, 4, 9, 11, 16]))
console.log(sortByHeight([1, 3, -1, 23, 43, -1, -1, 54, -1, -1, -1, 77]))