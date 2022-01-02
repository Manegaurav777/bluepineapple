const arr = ["asd", "asaf", "ada", "aaaadfda", "zzzzcc", "awerttyyy"];
const findLargest = (arr = []) => {
   if(!arr?.length){
      return '';
   };
   let res = '';
   res = arr.reduce((acc, val) => {
      return acc.length >= val.length ? acc : val;
   });
   return res;
};
console.log(findLargest(arr));