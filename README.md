# CDOSekai wplaceOverlay Template
- This is an open source code I grabbed from [clrfl](<https://github.com/clrfl>) when I was browsing the r/WplaceLive/ reddit forums
- You can find the original github repo [here](<https://github.com/clrfl/wplaceOverlay>) and the reddit post [here](<https://www.reddit.com/r/WplaceLive/comments/1me5ehv/i_developed_a_canvas_overlay_for_personal_use/>)
- This is only for the use of CDOSekai Members who want to help create our logo, or if any other wplace projects come up
- This code only works on PC/Laptop and I am too lazy to make it compatible for mobile *(will probably migrate to a different extension sometime soon)*
- You do not need to change any of the files and just need to clone the entire folder into your pc
- Do not make any commits or changes to the code, we will update this repository on our own
- If you are confused on how to install this/get it working, join our Discord Server [here](https://discord.gg/r6mbJwsFMd) and we can help yall out there

## Some weird bugs I noticed
- The program for some reason just refuses to work on the Brave Browser
  - So any of the following browsers work based on my experience: **Firefox**, **Chrome**,

- If you encounter any errors when running ```main.py```, just run the following commands on your cmd terminal
```
py -m pip install Pillow

py -m pip install curl_cffi
```


# Steps to Run The Program
- run ```main.py``` by opening a cmd terminal in the wplaceOverlay folder
- run the command ```python main.py```
- Open the browser tab that has [wplace.live](https://wplace.live/) running
- Press ```F12``` on your keyboard with the tab opened and navigate to the [browser console](https://imgur.com/a/lvQ9wkn)
  - *If this is your first time running the code, you will need to type ```allow pasting``` on the console so you can continue on with the next step*
- Paste the following code below *(which you can find in the ```browserpatch.js``` file)* in the browser console and run the code:
```
(async () => {
	let tilesconfig = await (await fetch("http://localhost:8000/config.json", {cache: 'reload'})).json();
	console.log(tilesconfig);
	fetch = new Proxy(fetch, {
		apply: (target, thisArg, argList) => {
			console.log(target, thisArg, argList);
			if (!argList[0]) {
				throw new Error("No URL provided to fetch");
			}

			const urlString = typeof argList[0] === "object" ? argList[0].url : argList[0];
			let url;

			try {
				url = new URL(urlString);
			} catch (e) {
				throw new Error("Invalid URL provided to fetch");
			}
			if (url.pathname != "/config.json") {
				var match = false;
				for (const configentry of tilesconfig) {
					if (url.pathname == "/files/s0/tiles/" + configentry[0] + "/" + configentry[1] + ".png") {
						match = true;
						break;
					}
				}

				if (url.hostname === "backend.wplace.live" && match) {
					url.host = "localhost:8000";
					url.protocol = "http";
					console.log("Modified URL:", url);

					if (typeof argList[0] === "object") {
						argList[0] = new Request(url, argList[0]);
					} else {
						argList[0] = url.toString();
					}
				}
			}
			return target.apply(thisArg, argList);
		}
	});
})();
```

## Everything should work properly if you followed the steps, Enjoy!
### If you have any questions, just let me know in the [CDOSekai Discord Server](https://discord.gg/r6mbJwsFMd)  
