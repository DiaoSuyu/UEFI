// parse the parameters sent through the dialog.
function queryString(parameter) {
	
	//query string
	//format of parameter in search string is Key=Value, ie: TotalDays=45
	var qStr = location.search.substring(1, location.search.length);
	
	var param_value = 0;
	//parameter is the "key" the "[0-9]+" is the 2 digit numeric value
	var reStr = parameter+"=[0-9]+";
	//match parameter in queryString
	var param_result = qStr.match(reStr);
	if (param_result == null) { //HTML file opened directly with a double click.
	 return param_value;				//No additional parameters in the url, match
	}														//could not find the string to search for.
	param_value = parseInt(param_result[0].substring(parameter.length+1),10);
	return param_value;
}

//function the runs when the dialog is called
function Preload() { 
	
	var daysAvailable = queryString("totaldays");	//total days in trial
	if (daysAvailable == 0) {											//Avoid division by 0 if parameter could
		daysAvailable = 45;													//not be found in the url because HTML
	}																							//file was opened directly.
	var daysRemaining = queryString("daysleft");
	var percent = daysRemaining/daysAvailable;		//percentage used
	
	var imgWidth = 294;														//background image width for dialog
	
	var percent = daysRemaining/daysAvailable;		//percentage used
	var percentStr = "";
	
	var reminder_overlay_div;											//reminder_overlay div
	
	// set days remaining value in text
	document.all.days.innerHTML=daysRemaining;
	
	//get reminder_overlay div
	reminder_overlay_div = document.getElementById('progress_bar_overlay');
	//calculate px
	percentStr = parseInt(imgWidth*percent) + "px";
	//change style
	reminder_overlay_div.style.width=percentStr;
}
