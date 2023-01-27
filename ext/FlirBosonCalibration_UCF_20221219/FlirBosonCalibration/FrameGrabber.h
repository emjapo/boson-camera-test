#pragma once
extern "C"
{
	__declspec(dllexport) void* CreateV16SDK();
	__declspec(dllexport) void DestroyV16SDK( void* handle );
	__declspec(dllexport) int LoadV16File( void* handle , const char* v16FilePath );
	__declspec(dllexport) long GetCameraSerialNumberFromV16( void* handle );
	__declspec(dllexport) float* GetTemperatureImageFromV16( void* handle );
	__declspec(dllexport) int GetFrameWidthFromV16( void* handle );
	__declspec(dllexport) int GetFrameHeightFromV16( void* handle );
	__declspec(dllexport) float GetFrameRateFromV16( void* handle );
	__declspec(dllexport) int GetTotalNumberOfFramesFromV16( void* handle );
	__declspec(dllexport) const char* GetGPSDateTimeUTCFromV16( void* handle );
	__declspec(dllexport) float GetGPSLatitudeFromV16( void* handle );
	__declspec(dllexport) float GetGPSLongitudeFromV16( void* handle );
	__declspec(dllexport) float GetGPSImageDirectionFromV16( void* handle );
	__declspec(dllexport) const char* GetGPSImageDirectionRefFromV16( void* handle );
	__declspec(dllexport) float GetGPSAltitudeInMetersFromV16( void* handle );
	__declspec(dllexport) int GetGPSAltitudeRefFromV16( void* handle );


	__declspec(dllexport) void* CreateRadiometricImgReaderHandle();
	__declspec(dllexport) void DestroyRadiometricImgReaderHandle( void* handle );
	__declspec(dllexport) int LoadRadiometricJpeg( void* handle , const char* v16FilePath );
	__declspec(dllexport) long GetCameraSerialNumberFromRadiometricJpeg( void* handle );
	__declspec(dllexport) float* GetTemperatureImageFromRadiometricJpeg( void* handle );
	__declspec(dllexport) int GetFrameWidthFromRadiometricJpeg( void* handle );
	__declspec(dllexport) int GetFrameHeightFromRadiometricJpeg( void* handle );
	__declspec(dllexport) const char* GetGPSDateTimeUTCFromRadiometricJpeg( void* handle );
	__declspec(dllexport) float GetGPSLatitudeFromRadiometricJpeg( void* handle );
	__declspec(dllexport) float GetGPSLongitudeFromRadiometricJpeg( void* handle );
	__declspec(dllexport) float GetGPSImageDirectionFromRadiometricJpeg( void* handle );
	__declspec(dllexport) const char* GetGPSImageDirectionRefFromRadiometricJpeg( void* handle );
	__declspec(dllexport) float GetGPSAltitudeInMetersFromRadiometricJpeg( void* handle );
	__declspec(dllexport) int GetGPSAltitudeRefFromRadiometricJpeg( void* handle );
	__declspec(dllexport) int GetAGCFromRadiometricJpeg( void* handle );
	__declspec(dllexport) float GetMinFromRadiometricJpeg( void* handle );
	__declspec(dllexport) float GetMaxFromRadiometricJpeg( void* handle );

	__declspec(dllexport) void* CreateFlirBosonRawCountsToTemperatureInCelsiusHandle();
	__declspec(dllexport) float* ConvertFlirBosonCameraRawCountsToTemperatureInCelsius( void* handle , uint16_t* rawCounts , int rawDataLen , uint32_t fpa , uint32_t cameraSerialNumber );
	__declspec(dllexport) void DestroyFlirBosonRawCountsToTemperatureInCelsiusHandle( void* handle );
}