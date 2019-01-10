# Qt IPCtrl
The IPCtrl is the Qt Ctrl,It is similar to MFC Ctrl CIPAddressCtrl.Please refer to the example program Qt_IPCtrl_test for use. It is a very simple ctrl.
## How to use
* Add the ipctrl.h and ipctrl.cpp to your Qt project
* New IPCtrl
* Set the ctrl pos ,then show.Or use Qt layout to show

## API
Get the string of IP form IPCtrl
* bool getIPStr(QString&);

Set the IP to IPCtrl
*	bool setIP(QString ipstr);

Check the input IP is correct
* bool isInPutComplete();
