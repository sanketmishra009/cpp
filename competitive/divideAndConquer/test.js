
u = "https://jsonplaceholder.typicode.com/posts";
var data;
function show(data) {
    var temp = []
    // console.log(data[0].userId);
    // console.log("inside show");
        let tab = `<tr>
          <th>userId</th>
          <th>Id</th>
          <th>Title</th>
          <th>Body</th>
         </tr>`;
         for(var i =0;i<data.length;i++){
             if(containsObject(temp, data[i].userId)){
                 tab+=`<tr><td></td>
                 <td>${data[i].id}</td><td>${data[i].title}</td><td>${data[i].body}</td></tr>`;
             }
             else{
                temp.push(data[i].userId);
             tab+=`<tr><td>${data[i].userId}</td>
<td>${data[i].id}</td><td>${data[i].title}</td><td>${data[i].body}</td></tr>`;
             }
         }
         document.getElementById("dTable").innerHTML = tab;
}
function containsObject(list, obj) {
    var i;
    for (i = 0; i < list.length; i++) {
        if (list[i] === obj) {
            return true;
        }
    }

    return false;
}
async function apiFetch(url){
    const response = await fetch(url);
     data = await response.json();
    groupBy(data, "userId");
    // console.log(data);
    show(data);
    }
    function groupBy(collection, property) {
    var i = 0, val, index,
        values = [], result = [];
    for (; i < collection.length; i++) {
        val = collection[i][property];
        index = values.indexOf(val);
        if (index > -1)
            result[index].push(collection[i]);
        else {
            values.push(val);
            result.push([collection[i]]);
        }
    }
    return result;
}

apiFetch(u);



async function getData(){
    const url = "https://jsonplaceholder.typicode.com/comments"
    const response = await fetch(url);
     data = await response.json();
    // console.log(data);
    return data;
    }

    const main = ()=>{
        var data =getData();
        data.then((res)=>{
            console.log(JSON.stringify(res));
        });
    }
    // main();


