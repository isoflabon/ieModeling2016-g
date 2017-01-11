
var history  = milkcocoa.dataStore('message').history();

history.sort('desc');
history.size(10);
history.limit(2000);

history.on('data',function(data){
    console.log(data);
});

history.run();
