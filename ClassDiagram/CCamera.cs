using System;
using System.Collections.Generic;
using System.Text;

namespace ClassDiagram
{
	public class CCamera
	{
		private int m_nPhi;
		private int m_nTheta;
		private CVector3 m_vLookAt;
		private CVector3 m_vUp;
		private float m_fDistance;

		public float GetDistance()
		{
			throw new System.NotImplementedException();
		}

		public void SetDistance(float fDistance)
		{
			throw new System.NotImplementedException();
		}

		public void Rotate(int nDegrees)
		{
			throw new System.NotImplementedException();
		}

		public void Tilt(int nDegrees)
		{
			throw new System.NotImplementedException();
		}

		public void SetLookAt(CVector3 vLookAt)
		{
			throw new System.NotImplementedException();
		}

		public CVector3 GetLookAt()
		{
			throw new System.NotImplementedException();
		}

		public CVector3 GetUp()
		{
			throw new System.NotImplementedException();
		}

		public void SetUp(CVector3 vUp)
		{
			throw new System.NotImplementedException();
		}
	}
}
