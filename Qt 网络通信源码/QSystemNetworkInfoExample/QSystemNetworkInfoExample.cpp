/****************************************************************************
**
** Trolltech hereby grants a license to use the Qt/Eclipse Integration
** plug-in (the software contained herein), in binary form, solely for the
** purpose of creating code to be used with Trolltech's Qt software.
**
** Qt Designer is licensed under the terms of the GNU General Public
** License versions 2.0 and 3.0 ("GPL License"). Trolltech offers users the
** right to use certain no GPL licensed software under the terms of its GPL
** Exception version 1.2 (http://trolltech.com/products/qt/gplexception).
**
** THIS SOFTWARE IS PROVIDED BY TROLLTECH AND ITS CONTRIBUTORS (IF ANY) "AS
** IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
** TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
** PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER
** OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
** EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
** PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
** LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
** NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** Since we now have the GPL exception I think that the "special exception
** is no longer needed. The license text proposed above (other than the
** special exception portion of it) is the BSD license and we have added
** the BSD license as a permissible license under the exception.
**
****************************************************************************/
#include <QAction>
#include "QSystemNetworkInfoExample.h"

QSystemNetworkInfoExample::QSystemNetworkInfoExample(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);

#ifdef Q_OS_SYMBIAN // adding softkey for Symbian
        QAction* backAction = new QAction( tr("Back"), this );
         backAction->setSoftKeyRole( QAction::NegativeSoftKey );
         connect(backAction, SIGNAL(triggered()), this, SLOT(close()));
         addAction( backAction );
#endif
	iSystemNetworkInfo = new QSystemNetworkInfo(this);
	
        ui.lineEdit_GSM->setText(GetStatusString(iSystemNetworkInfo->networkStatus(QSystemNetworkInfo::GsmMode)));
	ui.lineEdit_CDMA->setText(GetStatusString(iSystemNetworkInfo->networkStatus(QSystemNetworkInfo::CdmaMode)));
	ui.lineEdit_WCDMA->setText(GetStatusString(iSystemNetworkInfo->networkStatus(QSystemNetworkInfo::WcdmaMode)));
	ui.lineEdit_WLAN->setText(GetStatusString(iSystemNetworkInfo->networkStatus(QSystemNetworkInfo::WlanMode)));
        ui.lineEdit_EtherNet->setText(GetStatusString(iSystemNetworkInfo->networkStatus(QSystemNetworkInfo::EthernetMode)));
	ui.lineEdit_BlueTooth->setText(GetStatusString(iSystemNetworkInfo->networkStatus(QSystemNetworkInfo::BluetoothMode)));
	ui.lineEdit_WiMax->setText(GetStatusString(iSystemNetworkInfo->networkStatus(QSystemNetworkInfo::WimaxMode)));
	
	QSystemNetworkInfo::NetworkStatus status = QSystemNetworkInfo::UndefinedStatus;
	status = iSystemNetworkInfo->networkStatus(QSystemNetworkInfo::GsmMode);
	switch(status)
		{
		case QSystemNetworkInfo::HomeNetwork:
		case QSystemNetworkInfo::Roaming:
			ui.lineEdit_SignalStrength->setText(QString::number(iSystemNetworkInfo->networkSignalStrength(QSystemNetworkInfo::GsmMode), 10));
			ui.lineEdit_MacAddress->setText(iSystemNetworkInfo->macAddress(QSystemNetworkInfo::GsmMode));
			ui.lineEdit_NetworkName->setText(iSystemNetworkInfo->networkName(QSystemNetworkInfo::GsmMode));
			break;
		default:
			break;
		}
	
	status = iSystemNetworkInfo->networkStatus(QSystemNetworkInfo::CdmaMode);
	switch(status)
		{
		case QSystemNetworkInfo::HomeNetwork:
		case QSystemNetworkInfo::Roaming:
			ui.lineEdit_SignalStrength->setText(QString::number(iSystemNetworkInfo->networkSignalStrength(QSystemNetworkInfo::CdmaMode), 10));
			ui.lineEdit_MacAddress->setText(iSystemNetworkInfo->macAddress(QSystemNetworkInfo::CdmaMode));
			ui.lineEdit_NetworkName->setText(iSystemNetworkInfo->networkName(QSystemNetworkInfo::CdmaMode));
			break;
		default:
			break;
		}
	
	status = iSystemNetworkInfo->networkStatus(QSystemNetworkInfo::WcdmaMode);
	switch(status)
		{
		case QSystemNetworkInfo::HomeNetwork:
		case QSystemNetworkInfo::Roaming:
			ui.lineEdit_SignalStrength->setText(QString::number(iSystemNetworkInfo->networkSignalStrength(QSystemNetworkInfo::WcdmaMode), 10));
			ui.lineEdit_MacAddress->setText(iSystemNetworkInfo->macAddress(QSystemNetworkInfo::WcdmaMode));
			ui.lineEdit_NetworkName->setText(iSystemNetworkInfo->networkName(QSystemNetworkInfo::WcdmaMode));
			break;
		default:
			break;
		}
	
	status = iSystemNetworkInfo->networkStatus(QSystemNetworkInfo::WlanMode);
	switch(status)
		{
		case QSystemNetworkInfo::HomeNetwork:
		case QSystemNetworkInfo::Roaming:
			ui.lineEdit_SignalStrength->setText(QString::number(iSystemNetworkInfo->networkSignalStrength(QSystemNetworkInfo::WlanMode), 10));
			ui.lineEdit_MacAddress->setText(iSystemNetworkInfo->macAddress(QSystemNetworkInfo::WlanMode));
			ui.lineEdit_NetworkName->setText(iSystemNetworkInfo->networkName(QSystemNetworkInfo::WlanMode));
			break;
		default:
			break;
		}
	
	status = iSystemNetworkInfo->networkStatus(QSystemNetworkInfo::EthernetMode);
	switch(status)
		{
		case QSystemNetworkInfo::HomeNetwork:
		case QSystemNetworkInfo::Roaming:
			ui.lineEdit_SignalStrength->setText(QString::number(iSystemNetworkInfo->networkSignalStrength(QSystemNetworkInfo::EthernetMode), 10));
			ui.lineEdit_MacAddress->setText(iSystemNetworkInfo->macAddress(QSystemNetworkInfo::EthernetMode));
			ui.lineEdit_NetworkName->setText(iSystemNetworkInfo->networkName(QSystemNetworkInfo::EthernetMode));
			break;
		default:
			break;
		}	

	status = iSystemNetworkInfo->networkStatus(QSystemNetworkInfo::BluetoothMode);
	switch(status)
		{
		case QSystemNetworkInfo::HomeNetwork:
		case QSystemNetworkInfo::Roaming:
			ui.lineEdit_SignalStrength->setText(QString::number(iSystemNetworkInfo->networkSignalStrength(QSystemNetworkInfo::BluetoothMode), 10));
			ui.lineEdit_MacAddress->setText(iSystemNetworkInfo->macAddress(QSystemNetworkInfo::BluetoothMode));
			ui.lineEdit_NetworkName->setText(iSystemNetworkInfo->networkName(QSystemNetworkInfo::BluetoothMode));
			break;
		default:
			break;
		}	
	
	status = iSystemNetworkInfo->networkStatus(QSystemNetworkInfo::WimaxMode);
	switch(status)
		{
		case QSystemNetworkInfo::HomeNetwork:
		case QSystemNetworkInfo::Roaming:
			ui.lineEdit_SignalStrength->setText(QString::number(iSystemNetworkInfo->networkSignalStrength(QSystemNetworkInfo::WimaxMode), 10));
			ui.lineEdit_MacAddress->setText(iSystemNetworkInfo->macAddress(QSystemNetworkInfo::WimaxMode));
			ui.lineEdit_NetworkName->setText(iSystemNetworkInfo->networkName(QSystemNetworkInfo::WimaxMode));
			break;
		default:
			break;
		}
	
	ui.lineEdit_CellID->setText(QString::number(iSystemNetworkInfo->cellId(), 10));
	ui.lineEdit_LocationCode->setText(QString::number(iSystemNetworkInfo->locationAreaCode(), 10));
	
	ui.lineEdit_CurrentCountryCode->setText(iSystemNetworkInfo->currentMobileCountryCode());
	ui.lineEdit_CurrentNetworkCode->setText(iSystemNetworkInfo->currentMobileNetworkCode());
	ui.lineEdit_HomeCountryCode->setText(iSystemNetworkInfo->homeMobileCountryCode());
	ui.lineEdit_HomeNetworkCode->setText(iSystemNetworkInfo->homeMobileNetworkCode());
	
}

QSystemNetworkInfoExample::~QSystemNetworkInfoExample()
{
	if(iSystemNetworkInfo)
		{
		delete iSystemNetworkInfo;
		iSystemNetworkInfo = NULL;
		}
}

QString QSystemNetworkInfoExample::GetStatusString(QSystemNetworkInfo::NetworkStatus status)
	{
	QString returnString = "Undefined";
	switch(status)
		{
		case QSystemNetworkInfo::NoNetworkAvailable:
			returnString = "NoNetworkAvailable";
			break;
		case QSystemNetworkInfo::EmergencyOnly:
			returnString = "EmergencyOnly";
			break;
		case QSystemNetworkInfo::Searching:
			returnString = "Searching";
			break;
		case QSystemNetworkInfo::Busy:
			returnString = "Busy";
			break;
		case QSystemNetworkInfo::Connected:
			returnString = "Connected";
			break;
		case QSystemNetworkInfo::HomeNetwork:
			returnString = "HomeNetwork";
			break;
		case QSystemNetworkInfo::Denied:
			returnString = "Denied";
			break;
		case QSystemNetworkInfo::Roaming:
			returnString = "Roaming";
			break;
		default:
			returnString = "Undefined"; 
		break;
		}
	return returnString;
	}
