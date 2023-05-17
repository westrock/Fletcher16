#include <Fletcher16.h>

void setup()
{
	Serial.begin(9600);  // Serial port to computer

	uint16_t csum;
	Fletcher16::CheckBytes checkBytes;
	char data[32] = "abcde";
	size_t dataLen = strlen(data);

	// Calculate the checksum and validate the result
	csum = Fletcher16::GetChecksum((const uint8_t*)data, dataLen);
	if (csum == 51440)
	{
		Serial.println(F("GetChecksum() succeeded"));
	}
	else
	{
		Serial.println(F("GetChecksum() failed"));
	}

	// Get the checkbytes.  The purpose of the checkbytes is when they are
	// appended to the original string, it's checksum should be zero (0).
	csum = Fletcher16::GetCheckBytes((const uint8_t*)data, dataLen);
	if (csum == 51270)
	{
		Serial.println(F("GetCheckBytes() succeeded"));
	}
	else
	{
		Serial.println(F("GetCheckBytes() failed"));
	}

	// Calculate the checkbytes and append them to the original string.
	// Return the checkbytes.  Should be the same as returned by GetCheckBytes() above.
	checkBytes.bothBytes16 = Fletcher16::GetAndAppendCheckBytes((uint8_t *)data, dataLen);
	if (checkBytes.bothBytes16 == csum)
	{
		Serial.println(F("GetAndAppendCheckBytes() succeeded"));
	}
	else
	{
		Serial.println(F("GetAndAppendCheckBytes() failed"));
	}

	// Calculate the checksum of the ammended string.  It should return 0.
	// In some applications the ammended string is sent/received.  In others
	// the original string is, the checkbytes are generated, and the checksum
	// of the string with checkbytes is compared to 0.  Your choice.
	csum = Fletcher16((const uint8_t*)data, strlen(data));
	if (csum == 0)
	{
		Serial.println(F("Fletcher16() check succeeded"));
	}
	else
	{
		Serial.println(F("Fletcher16() check failed"));
	}
}
}

void loop()
{
  exit(0);
}

